import "DPI-C" function int simple_add(input int a, input int b);

module top;
    initial begin
        int a, b;
        a = 40;
        b = 2;
        $display("function simple_add --> %0d + %0d = %0d\n", a, b, simple_add(a, b));
    end
endmodule