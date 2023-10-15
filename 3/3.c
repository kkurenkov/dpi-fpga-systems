#include <stdio.h>

extern void throw_display_sv();
extern void throw_uvm_error_sv  ();
extern void throw_uvm_warning_sv();

void function_c_display() {
    throw_display_sv("function_c_display MESSAGE");
}

void function_c_error() {
    throw_uvm_error_sv("function_c_error MESSAGE");
}

void function_c_warning() {
    throw_uvm_warning_sv("function_c_warning MESSAGE");
}