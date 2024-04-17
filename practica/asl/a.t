function f1
  vars
    x1 integer
    y1 integer
  endvars

     writes "err!!\n"
     %1 = 2
     %2 = y1 * %1
     %3 = x1 == %2
     ifFalse %3 goto endif1
     %4 = 3
     %5 = y1 + %4
     x1 = %5
     %6 = y1 * x1
     %7 = x1 + %6
     y1 = %7
  label endif1 :
     return
endfunction

function main
  vars
    x1 integer
  endvars

     %1 = 0
     x1 = %1
     %2 = 1
     %3 = x1 == %2
     ifFalse %3 goto endif1
     call f1
  label endif1 :
     %4 = 4
     %5 = 5
     %6 = %4 * %5
     %7 = 6
     %8 = %6 + %7
     x1 = %8
     writei x1
     writes "\n"
     return
endfunction


