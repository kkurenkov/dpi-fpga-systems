// Если вызывать функцию , внутри которой есть вызов SV (в нашем случае это функция sv_display),
// то обязательно должно быть ключевое слово context,
// иначе будет ошибка
// xmsim: *E,NONCONI: The C identifier "sv_display" representing an export task/function cannot be executed from a non-context 
import "DPI" context function void c_display(); 

export "DPI" function sv_display;

function void sv_display();
    $display("SV: in sv_display\n");
endfunction

module top;
    initial
        c_display();
endmodule


