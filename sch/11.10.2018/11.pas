var x, y, c : integer;


procedure cut_last_digit(var n, d : integer);
begin
	d := n mod 10;
	n := n div 10;
end;


begin
	readln(x);
	
	c := 0;
	
	while x <> 0 do
	begin 
		cut_last_digit(x, y);

		if y mod 2 = 0 then
			c := c + 1;
	end;

	writeln(c);
end.


