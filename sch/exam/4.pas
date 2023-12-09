var s, i : integer;

begin
	s := 0;
	for i := 1 to 49 do
		if i mod 2 = 0 then
			s += i;
	writeln(s);
end.
