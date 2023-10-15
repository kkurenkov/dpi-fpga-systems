import "DPI-C" function int summ_array(input int v[]);

module top;
int arr[4];
int dynArr[];
int ret;
int x;

initial begin
    arr = {4, 5, 6, 7};
    ret = summ_array(arr);
    $display("ret = %0d \n", ret);

    x = 6;
    dynArr = new[x];
    dynArr = {8, 9, 10, 11, 12, 13};
    ret = summ_array(dynArr);
    $display("ret = %0d \n", ret);

    x = 9;
    dynArr = new[x];
    dynArr = {8, 9, 10, 11, 12, 13, 44, 45, 46};
    ret = summ_array(dynArr);
    $display("ret = %0d \n", ret);
end
endmodule