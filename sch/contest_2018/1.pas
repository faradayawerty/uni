var n, c : integer;


begin
	c := 0;

	for n := 000 to 999 do
	begin
		if (n mod 10 = n div 10 mod 10) or (n mod 10 = n div 100) or (n div 10 mod 10 = n div 100) then
			c += 1;
	end;

	writeln(c / 1000);
end.

