var i, a, b, c, d : integer;

begin
	for i := 1000 to 9999 do
	begin
		a := i mod 10; 		{последняя цифра}
		b := i div 10 mod 10; 	{предпоследняя цифра}
		c := i div 100 mod 10; 	{вторая цифра}
		d := i div 1000 mod 10; {первая цифра}

		if (a <> b) and (a <> c) and (a <> d) and (b <> c) and (b <> d) and (c <> d) then
			writeln(i);
	end;
end.
