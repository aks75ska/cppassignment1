#include "akgoyal_op.h"
#include <iostream>

using namespace std;

float add (float x, float y)
{
  try {
	  float result;
	  result=x+y;
	  return result;
  }
  catch( const exception &exc ) {
	  cerr << exc.what();
  }
}

int add (int x, int y)
{
  try {
	  int result;
	  result=x+y;
	  return result;
  }
  catch( const exception &exc ) {
	  cerr << exc.what();
  }
}

float subtract (float x, float y)
{
  try {
	  float result;
	  result=x-y;
	  return result;
  }
  catch( const exception &exc ) {
	  cerr << exc.what();
  }
}

int subtract (int x, int y)
{
  try {
	  int result;
	  result=x-y;
	  return result;
  }
  catch( const exception &exc ) {
	  cerr << exc.what();
  }
}

float multiply (float x, float y)
{
  try {
	  float result;
	  result=x*y;
	  return result;
  }
  catch( const exception &exc ) {
	  cerr << exc.what();
  }
}

int multiply (int x, int y)
{
  try {
	  int result;
	  result=x*y;
	  return result;
  }
  catch( const exception &exc ) {
	  cerr << exc.what();
  }
}

float divide (float x, float y)
{
  try {
	  float result;
	  result=x/y;
	  return result;
  }
  catch( const exception &exc ) {
	  cerr << exc.what();
  }
}

int mod (int x, int y)
{
  try {
	  int result;
	  result=x%y;
	  return result;
  }
  catch( const exception &exc ) {
	  cerr << exc.what();
  }
}