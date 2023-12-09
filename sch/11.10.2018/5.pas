var n : integer;


function p(x, y : integer) : integer; 
begin
	if y = 0 then
		p := 1
	else 
		p := x * p(x, y - 1);
end;


begin
	readln(n);
	writeln( p(2, n) );
end.


