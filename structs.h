#ifndef PSOTNIC_STRUCTS_H
#define PSOTNIC_STRUCTS_H 1

#include "pstring.h"

class comment;
class inetconn;
class HANDLE;

struct pojebyHeader
{
	char id[8];
	unsigned int version;
};

struct unit_table
{
	char unit;
	int  ratio;
};

struct IOBUF
{
	char *buf;
	int pos;
	int len;
};

struct SOCKBUF
{
	int fd;
	char *buf;
	int len;
	int pos;
};

struct EXPANDINFO
{
	pstring<8> system;
	pstring<8> release;
	pstring<8> arch;
	pstring<8> version;
	pstring<8> realname;
};

struct flagTable
{
	const char letter;
	unsigned int flag;
	int level;
	unsigned int enforced;
	const char *desc;
	const char *long_desc;
};

struct partyline_commands
{
	const char *command;
	int (*func)(inetconn *c, char *data, char arg[][MAX_LEN], int argc);
	int min_args;
	const char *syntax;
	bool main_only;
};

struct bot_commands
{
        const char *command;
        int (*func)(HANDLE *h, const char *data, char arg[][MAX_LEN], int argc);
        int min_args;
        const char *syntax;
};

#endif
