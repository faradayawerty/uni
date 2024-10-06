var x1, y1, x2, y2 : real;


function f(a, b : real) : real;
begin
	f := sqr(a - b);
end;


begin
	readln(x1);
	readln(y1);
	readln(x2);
	readln(y2);

	writeln(sqrt(f(x1, x2) + f(y1, y2)));
end.


