#include <stdio.h>
#include <stdlib.h>

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  int year;
} Student;

void print_student(Mode m, Student s) {
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name);
      break;
	case MAJOR_AND_NAME:
	  printf("%s %s %s\n", s.major, s.first_name, s.last_name);
	  break;
	case YEAR_AND_NAME:
	  printf("%d %s %s\n", s.year, s.first_name, s.last_name);
	  break;
	default:
	  break;
  }
}

int main(int argc, char **argv) {
  Mode format = atoi(argv[1]);
  int numStudents = (argc-2)/4;
  char **studentList = argv+2;
  Student student;
  for(int i = 0; i < numStudents; i++) {
		student.first_name = studentList[4*i];
		student.last_name = studentList[4*i + 1];
		student.major = studentList[4*i + 2];
		student.year = atoi(studentList[4*i + 3]);
		print_student(format, student);
  }
  return 0;
}