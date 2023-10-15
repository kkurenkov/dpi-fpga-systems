`include "uvm_macros.svh"
import uvm_pkg::*;

import "DPI" context function void function_c_display(); 
import "DPI" context function void function_c_error  (); 
import "DPI" context function void function_c_warning(); 

export "DPI-C" function throw_display_sv    ;
export "DPI-C" function throw_uvm_error_sv  ;
export "DPI-C" function throw_uvm_warning_sv;

function void throw_display_sv(string msg);
    $display({"DPI-C INFO: ", msg, $sformatf(" TIME = %0t", $time())});
endfunction : throw_display_sv

function void throw_uvm_error_sv(string msg);
    `uvm_error("DPI-C", msg)
endfunction : throw_uvm_error_sv

function void throw_uvm_warning_sv(string msg);
    `uvm_warning("DPI-C", msg)
endfunction : throw_uvm_warning_sv

module top;
    initial begin
        function_c_display();
        #100;
        function_c_display();        
        #100;
        function_c_error();
        #100;
        function_c_warning();
    end
endmodule


