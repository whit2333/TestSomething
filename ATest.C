#include <stdio.h>
#include <getopt.h>
#include "TestSomething.h"
#include "TRint.h"

#define PACKAGE    "getoptex"
#define VERSION    "0.0.1"

void print_help(int exval);
void list_measurments();
void print_experiments();

int main(int argc, char *argv[]) {
   int opt;
   // no arguments given
   if(argc == 1) {
      fprintf(stderr, "This program needs arguments....\n\n");
      print_help(1);
   }
   int fnargs = 2;
   char * fargs[2] = {"atest","-l"};
   TRint * theApp = new TRint("atest",  &fnargs, &fargs[0], NULL, 2);

   while((opt = getopt(argc, argv, "lhVvaf:o:")) != -1) {
      switch(opt) {
         case 'h':
            print_help(0);
            break;
         case 'V':
            printf("%s %s\n\n", PACKAGE, VERSION); 
            return(0);
            break;
         case 'v':
            printf("%s: Verbose option is set `%c'\n", PACKAGE, optopt);
            break;
         case 'l':
            list_measurments();
            break;
         case 'a':
            printf("List the measurments \n");
            break;
         case 'f':
            printf("%s: Filename %s\n", PACKAGE, optarg);
            break;
         case 'o':
            printf("Output: %s\n", optarg);
            break;
         case ':':
            fprintf(stderr, "%s: Error - Option `%c' needs a value\n\n", PACKAGE, optopt);
            print_help(1);
            break;
         case '?':
            fprintf(stderr, "%s: Error - No such option: `%c'\n\n", PACKAGE, optopt);
            print_help(1);
      }
   }

   /* 
   // print all remaining options
    */
   for(; optind < argc; optind++)
      printf("argument: %s\n", argv[optind]);

   return 0;
}

void print_help(int exval) {
   printf("=========================================\n");
   printf("%s,%s show working getopt example\n", PACKAGE, VERSION); 
   printf("%s [-h] [-V] [-f FILE] [-o FILE]\n\n", PACKAGE);
   printf("  -h              print this help and exit\n");
   printf("  -V              print version and exit\n\n");
   printf("  -v              set verbose flag\n");
   printf("  -l              list the measurements\n");
   printf("  -f FILE         set intput file\n");
   printf("  -o FILE         set output file\n\n");
   printf("=========================================\n");
}

void list_measurments(){
   TestSomething * asdf = new TestSomething("asdf","jdhdfhdkjfkh");
   asdf->Dump();
}

void print_experiments(){


}

