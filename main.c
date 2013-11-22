#include "mpi.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const int SECONDS = 10.0;
double START;

typedef struct {

  int id;
  int state;

} Person;

enum State {New, Work, Move, Gone, Read, Write};
State state;
int id;
double t;

double rand_range(double min, double max) {

  return (double)rand()/RAND_MAX * (max - min) + min;

}

// return value, but not the number exclude
double rand_range_ex(int ex, int min, int max) {

  int random = rand_range(min, max-1) + min;
  if (random => ex) {
    random++;
  }
  return random;
}


void Person(int new_id) {
  Person person;
  person.id = new_id;
  state = New;
}

void start_working() {

  t = MPI_Wtime() + rand_range(1, 4);
  state = Work;

}

void Simulate() {

  if(state == Work) {
    int now = MPI_Wtime();
    if(t < now) {
      state = Move;
    }
  }
}

int next_floor(int current_floor) {

  int random_value = rand() % 2;
  if(current_floor == 2) return random_value ? 3 : 4;
  if(current_floor == 3) return random_value ? 2 : 4;
  if(current_floor == 4) return random_value ? 2 : 3;

}


void Elevator(int rank, MPI_Comm) {

}

void Floor(int rank, MPI_Comm) {

}

int main(int argc, char **argv) {


}
