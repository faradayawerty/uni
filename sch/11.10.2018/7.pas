var x, y, s : integer;


procedure read_xy();
begin
	readln(x);
	readln(y);
end;


procedure add_xy;
begin
	s := x + y;
end;


procedure write_sum;
begin
	writeln(s);
end;


begin
	read_xy;
	add_xy;
	write_sum;
end.


