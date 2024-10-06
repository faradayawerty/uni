var s, i : longint;

begin
   s := 0;

   for i := 100 to 999 do
        if i mod 2 = 1 then
            s += i;
   writeln(s);
end.

