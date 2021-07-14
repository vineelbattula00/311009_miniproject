#include "unity.h"
#include "1.h"
#include "2.h"
#include "3.h"
#include "4.h"
#include "5.h"
#include "6.h"
#include "structures.h"
#include"unity_internals.h"
#include"unity.h"

/* Required by the unity test framework */
void setUp(){}

/* Required by the unity test framework */
void tearDown(){}


void test_login(void){
    TEST_ASSERT_EQUAL(void,login("username","passwordsbanls"));
}

void test_Create_A_New_Bill(void){
    TEST_ASSERT_EQUAL(void,Create_A_New_bill("vineel","9346750631","maggi","2",);
}

void test_Delete_An_Incorrect_Bill(void){
    TEST_ASSERT_EQUAL(void,Delete_An_Incorrect_Bill("13")
}

int main(){
    UNITY_BEGIN();
    RUN_TEST(test_login);
    RUN_TEST(test_Create_A_New_Bill);
    RUN_TEST(test_Delete_An_Incorrect_Bill);
    
    return UNITY_END();
}
