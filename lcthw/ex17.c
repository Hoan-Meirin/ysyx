#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// #define MAX_DATA 512
// #define MAX_ROWS 100

struct Address {
    int id;
    int set;
    char *name;
    char *email;
};

struct Database {
    struct Address *rows;
	int max_data;
	int max_rows;
};

struct Connection {
    FILE *file;
    struct Database *db;
};
void Database_close(struct Connection *conn);
void die(const char *message,struct Connection *conn)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

	Database_close(conn);

    exit(1);
}

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n",
            addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
	// if(fread(conn->db->rows->email, sizeof(char) * conn->db->max_data, 1, conn->file) != 1) die("Failed to load emails.",conn);
	// if(fread(conn->db->rows->name, sizeof(char) * conn->db->max_data, 1, conn->file) != 1) die("Failed to load names.",conn);
	for(int i = 0; i < conn->db->max_rows; i++)
	{
		if(conn->db->rows[i].set)
		{
			fread(conn->db->rows[i].email, sizeof(char) * conn->db->max_data, 1, conn->file);\
			if(!conn->db->rows[i].email) die("Failed to load emails.",conn);
			fread(conn->db->rows[i].name, sizeof(char) * conn->db->max_data, 1, conn->file);
			if(!conn->db->rows[i].name) die("Failed to load names.",conn);
		}
	}

}

struct Connection *Database_open(const char *filename, char mode,int max_data,int max_rows)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error",conn);

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("Memory error",conn);
	conn->db->max_data = max_data;
	conn->db->max_rows = max_rows;
	conn->db->rows = malloc(sizeof(struct Address) * max_rows);
	if(!conn->db->rows) die("Memory error",conn);

	for (int i = 0; i < max_rows; i++) {
        conn->db->rows[i].name = malloc(max_data); // +1 for null terminator
        conn->db->rows[i].email = malloc(max_data);
        if (!conn->db->rows[i].name || !conn->db->rows[i].email) die("Memory error", conn);
    }

    if (mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            Database_load(conn);
        }
    }

    if(mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if(conn->file) {
            Database_load(conn);
        }
    }

    if(!conn->file) die("Failed to open the file",conn);

    return conn;
}

void Database_close(struct Connection *conn)
{
    if (conn) {
        if (conn->file) fclose(conn->file);

        if (conn->db) {
            if (conn->db->rows) {
                for (int i = 0; i < conn->db->max_rows; i++) {
                    free(conn->db->rows[i].name);
                    free(conn->db->rows[i].email);
                }
                free(conn->db->rows);
            }
            free(conn->db);
        }
        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to write database.",conn);
	if(fwrite(conn->db->rows, sizeof(struct Address) * conn->db->max_rows, 1, conn->file) != 1) die("Failed to write addresses.",conn);
	for(int i = 0; i < conn->db->max_rows; i++)
	{
		if(conn->db->rows[i].set)
		{
			if(fwrite(conn->db->rows[i].email, sizeof(char) * conn->db->max_data, 1, conn->file) != 1)
			die("Failed to write emails.",conn);
			if(fwrite(conn->db->rows[i].name, sizeof(char) * conn->db->max_data, 1, conn->file) != 1)
			die("Failed to write names.",conn);
			
		}
	}

    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database.",conn);
}

void Database_create(struct Connection *conn)
{
    int i = 0;

    for(i = 0; i < conn->db->max_rows; i++) {
        // make a prototype to initialize it
        struct Address addr = {.id = i, .set = 0};
        // then just assign it
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    struct Address *addr = &conn->db->rows[id];
    if(addr->set) die("Already set, delete it first",conn);

    addr->set = 1;
    // WARNING: bug, read the "How To Break It" and fix this
    char *res = strncpy(addr->name, name, conn->db->max_data);
	res[conn->db->max_data - 1] = '\0';
    // demonstrate the strncpy bug
    if(!res) die("Name copy failed",conn);


    res = strncpy(addr->email, email, conn->db->max_data);
    if(!res) die("Email copy failed",conn);
	res[conn->db->max_data - 1] = '\0';
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];

    if(addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set",conn);
    }
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < conn->db->max_rows; i++) {
        struct Address *cur = &db->rows[i];

        if(cur->set) {
            Address_print(cur);
        }
    }
}


struct Address* find(struct Connection *conn, char *name) // finds the address with the given name
{
	for (int i = 0; i < conn->db->max_rows; i++) {
		if(strncmp(conn->db->rows[i].name, name,conn->db->max_data) == 0)
		{
			if(conn->db->rows[i].set)
				return &conn->db->rows[i];
			else
			{
				printf("ERROR: %s\n", "ID not set.");
				return NULL;
			}
		}
		else if(i==conn->db->max_rows-1)
		{
			printf("ERROR: %s\n", "ID not found.");
			return NULL;
		}
			
	}
}													// good AI,i will close it

int main(int argc, char *argv[])
{

    char *filename = argv[1];
    char action = argv[2][0];

	int max_data = 512;
	int max_rows = 128;
    struct Connection *conn = Database_open(filename, action,max_data,max_rows);
    int id = 0;
    if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]",conn);

    if(argc > 3) id = atoi(argv[3]);
    if(id >= conn->db->max_rows) die("There's not that many records.",conn);

		printf("****************************************\n");
    switch(action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

        case 'g':
            if(argc != 4) die("Need an id to get",conn);

            Database_get(conn, id);
            break;

        case 's':
            if(argc != 6) die("Need id, name, email to set",conn);

            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd':
            if(argc != 4) die("Need id to delete",conn);

            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;
        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list",conn);
    }

    Database_close(conn);

    return 0;
}



/*
	附加题第一题：完成
	附加题第二题：因为改成参数传入有点麻烦，就单纯用局部变量了。改成参数只需要加atoi函数和把所有其他参数后移
	附加题第三题：用name进行寻找，找到后返回地址，找不到返回NULL
	附加题第四题：内存对齐的原则
	附加题第五题：没看懂要我干什么
	附加题第六题：后面再写吧，shell脚本我目前写不出能检查错误的，不过应该可以通过stderr检查
	附加题第七题：省去传参的操作，但是全局变量储存在数据段，不能动态分配内存
	附加题第八题：实现见ex17_stack.c




*/