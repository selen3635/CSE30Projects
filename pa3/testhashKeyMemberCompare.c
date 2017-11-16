

#include <string.h>
#include "test.h"
#include "pa3.h"

void testhashKeyMemberCompare() {

  struct anagram ana1, ana2;

  const char * anaString1 = "string1";
  const char * anaString2 = "string2";

  TEST( createAnagram( anaString1, &ana1 ) == 0 );
  (void) printf("hashValue of ana1: %d\n", ana1.hashKey);

  TEST( createAnagram( anaString2, &ana2 ) == 0 );
  (void) printf("hashValue of ana2: %d\n", ana2.hashKey);

  TEST( hashKeyMemberCompare( &ana1, &ana2 ) == -1 );


  struct anagram ana3, ana4;

  const char * anaString3 = "thisisastring";
  const char * anaString4 = "thisisanotherstring";

  TEST( createAnagram( anaString3, &ana3 ) == 0 );
  (void) printf("hashValue of ana3: %d\n", ana3.hashKey);

  TEST( createAnagram( anaString4, &ana4 ) == 0 );
  (void) printf("hashValue of ana4: %d\n", ana4.hashKey);

  TEST( anagramCompare( &ana3, &ana4) == 1 );
  (void) fprintf(stdout, "strcmp result %d\n", strcmp("thisisastring", "thisisanotherstring"));
  (void) fprintf(stdout, "anagram test 3 & 4 : %d\n", anagramCompare( &ana3, &ana4 ) );

  TEST( hashKeyMemberCompare( &ana3, &ana4 ) == 1 );
  (void) fprintf(stdout, "%d", hashKeyMemberCompare( &ana3, &ana4 ) );




  struct anagram ana5, ana6;

  const char * anaString5 = "string5";
  const char * anaString6 = "string6";

  TEST( createAnagram( anaString5, &ana5 ) == 0 );
  (void) printf("hashValue of ana5: %d\n", ana5.hashKey);

  TEST( createAnagram( anaString6, &ana6 ) == 0 );
  (void) printf("hashValue of ana6: %d\n", ana6.hashKey);

  TEST ( anagramCompare( &ana6, &ana5 ) == 1 );
  (void) fprintf(stdout, "anagram test 6 & 5 : %d\n", anagramCompare( &ana6, &ana5 ) );
  TEST( hashKeyMemberCompare( &ana5, &ana6 ) == -1 );


  struct anagram ana7, ana8;

  const char * anaString7 = "string222";
  const char * anaString8 = "222string";

  TEST( createAnagram( anaString7, &ana7 ) == 0 );
  (void) printf("hashValue of ana7: %d\n", ana7.hashKey);

  TEST( createAnagram( anaString8, &ana8 ) == 0 );
  (void) printf("hashValue of ana8: %d\n", ana8.hashKey);

  TEST( anagramCompare( &ana8, &ana7 ) == -1 );
  (void) fprintf(stdout, "strcmp result %d\n", strcmp("string222", "222string"));
  (void) fprintf(stdout, "anagram test 7 & 8 : %d\n", anagramCompare( &ana8, &ana7 ) );
  TEST( hashKeyMemberCompare( &ana7, &ana8 ) == 0 );

  struct anagram ana9, ana10;
  
  const char * anaString9 = "string222";
  const char * anaString10 = "string222";

  TEST( createAnagram( anaString9, &ana9 ) == 0 );
  (void) printf("hashValue of ana7: %d\n", ana7.hashKey);

  TEST( createAnagram( anaString10, &ana10 ) == 0 );
  (void) printf("hashValue of ana8: %d\n", ana8.hashKey);

  TEST( anagramCompare( &ana9, &ana10 ) == 0 );
  (void) fprintf(stdout, "anagram test 9 & 10 : %d\n", anagramCompare( &ana9, &ana10 ) );
  TEST( hashKeyMemberCompare( &ana9, &ana10 ) == 0 );



}

int main() {
  testhashKeyMemberCompare();
  return 0;
}


