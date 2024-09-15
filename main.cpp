#include <systemc.h>

SC_MODULE(Hello_SystemC) {
    SC_CTOR(Hello_SystemC) {
        SC_THREAD(say_hello);
    }

    void say_hello() {
        std::cout << "Hello, SystemC!" << std::endl;
    }
};

int sc_main(int argc, char* argv[]) {
    sc_uint<4> a = 5;

    Hello_SystemC hello("HELLO");
    sc_start();
    return 0;
}
