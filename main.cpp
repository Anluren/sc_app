#include <gtest/gtest.h>
#include <systemc.h>
#include "ac_int.h"
#include "ac_sc.h"

SC_MODULE(Hello_SystemC){SC_CTOR(Hello_SystemC){SC_THREAD(say_hello);
}

void say_hello() { std::cout << "Hello, SystemC!" << std::endl; }
}
;

TEST(HelloSystemCTest, BasicTest) {
  sc_uint<4> a = 5;
  ASSERT_EQ(a, 5);
}

int sc_main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);

  sc_uint<4> a = 5;

  sc_biguint<63> sc_var(4);
  auto ac_var = to_ac(sc_var);
  auto new_sc_var = to_ac(sc_var);

  EXPECT_EQ(sc_var, new_sc_var);
  auto ret_code = RUN_ALL_TESTS();
  if (ret_code != 0) {
    std::cerr << "ERROR: Some tests failed." << std::endl;
    return ret_code;
  }

  Hello_SystemC hello("HELLO");
  sc_start();
  return 0;
}
