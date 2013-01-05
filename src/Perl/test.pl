#!/usr/bin/perl

BEGIN{push(@INC,"/home/casper/Projects/src/Perl")};

use srcFile;
use strict;

my $file = new SrcFile;

$file->ApdInc("auto.c", "#include <stdlib.h>\n");
$file->ApdInc("auto.c", "#include <stdio.h>\n\n");
$file->ApdMac("auto.c", "#define MAX 10\n");
$file->ApdMac("auto.c", "#define MIN 1\n\n");
$file->ApdStr("auto.c", "typedef struct Int{int a;};\n");
$file->ApdStr("auto.c", "typedef struct Float{float c;};");
$file->ApdFun("auto.c", "char * GetInt(const Int *value){return value->a;}");
$file->ApdFun("auto.c", "char * GetFloat(const Float *value){return value->c;}");

$file->ApdFun("auto.h", "char * GetInt(const Int *value);");
$file->ApdFun("auto.h", "char * GetFloat(const Float *value);");
