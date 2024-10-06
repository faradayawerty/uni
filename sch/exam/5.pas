var s, i : integer;

begin
	s := 0;
	for i := 16 to 59 do
		if (i mod 10 = 2 and i mod 2 = 0) or (i mod 10 = 4 and i mod 4 = 0) or (i mod 10 = 6 and i mod 6 = 0) then
			s += i;
	writeln(s);
end.

