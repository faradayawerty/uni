var n, g : integer;


begin
	readln(n);
	readln(g);

	while n <> 0 do
	begin
		write(n mod g);
		n := n div g;
	end;
end.

