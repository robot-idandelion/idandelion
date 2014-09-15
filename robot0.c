/**************************************************************************************************/
/* Copyright (C), robot, 2014-2015                                                                */
/*                                                                                                */
/* FILE NAME             : menu.c                                                                 */
/* PRINCIPAL AUTHOR      : Robot                                                                  */
/* SUBSYTEM NAME         : menu                                                                   */
/* MODULE NAME           : menu                                                                   */
/* LANGUAGE              : C                                                                      */
/* TARGET ENVIRONMENT    : ANY                                                                    */
/* DATE OF FIRST RELEASE : 201/09/12                                                              */
/* DESCRIPTION           : This is a menu program                                                 */
/**************************************************************************************************/ 

/*
 *Revision log:
 *
 *Created by robot,2014/09/13
 *
 */

#include <stdio.h>
#include <stdlib.h>

/*  define and  statement   */
int Help();
void Find_Cmd( char * inputcmd);

typedef struct DataNode
{
    char *  cmd;
    char *  desc;
    int     (*handler)();
    struct  DataNode * next;
} tDataNode;


/*  data and program */
static tDataNode head[] =
{
    {
        "help", "this is help cmd!", Help, &head[1]
    },
    {
        "version", "menu program v1.0", NULL, &head[2]
    },
    {
        "author", "this is robot", NULL, NULL
    }
};

main()
{
    char * inputcmd;
    while(1)
    {
        printf("please input a cmd >");
        scanf("%s", inputcmd);
        Find_Cmd(inputcmd);
    }
}
 
int Help()
{
    tDataNode * p = head;
    printf("menu list:\n");
    while(p != NULL)
    {
        printf("%s - %s\n", p->cmd, p->desc );
        p = p->next;
    }
    return 0;
}
  
void Find_Cmd(char * inputcmd)
{ 
    tDataNode * p = head;
    while(p != NULL)
    {
        if(!strcmp(p->cmd, inputcmd))
        {
            printf("%s - %s\n", p->cmd, p->desc );
            if(p->handler != NULL)
            {
                p->handler();
            }
            break;
        }
        p = p->next;
    }
    if(p ==NULL)
    {
        printf("this is a wrong cmd!\n");
    }
}

