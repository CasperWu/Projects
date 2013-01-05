#!/usr/bin/perl

BEGIN{push(@INC,"/home/casper/Projects/perl")};

use srcFile;
use strict;

my $file = new SrcFile;

$file->ApdInc("cmfOrder.c", "#include <stdlib.h>\n");
$file->ApdInc("cmfOrder.c", "#include <stdio.h>\n");
$file->ApdMac("cmfOrder.c", "#define MAX 5\n");
$file->ApdMac("cmfOrder.c", "#define MIN 7\n");
$file->ApdStr("cmfOrder.c", "typedef struct ABC{int a;};\n");
$file->ApdStr("cmfOrder.c", "typedef struct DEF{float c;};");
$file->ApdFun("cmfOrder.c", "char * GetName1(char *ptr){while(1){int a=2;}}");
$file->ApdFun("cmfOrder.c", "char * GetName2();");

$file->ApdFun("midMsg.c", "char * GetMidMsg();char * GetMidMsg2();");
