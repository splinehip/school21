#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct cli_s    cli_t, *op;
typedef struct cli_op_s cli_op_t;

struct cli_op_s
{
    cli_t   *self;
    op (*PrintClient)(int);
};

struct cli_s
{
    int         id;
    cli_op_t    op;
};

op PrintClient(int a)
{
    cli_t *self = (cli_t *)(PrintClient - sizeof(PrintClient));
    printf("Client id: %d, a %d\n", self->id, a);
    //return self->op.PrintClient(self);
}
//#define "op.PrintClient(...)" op.PrintClient(op.self, __VA_ARGS__)
//#define op_PrintClient(...) PrintClient(&cl, __VA_ARGS__)

cli_t   new_client(int id)
{
    cli_t   c;
    c.id = id;
    c.op.self = &c;
    c.op.PrintClient = PrintClient;
    return c;
}

int main(void)
{
    cli_t   cl;

    cl = new_client(114);
    cl.op.self = &cl;
    cl.op.PrintClient(14);

    return 0;
}
