const r = 5;
const a = 4;
const b = 3;


var x, y : real;
var n, k : integer;


function f(x, y : real) : real;
begin
	f := sqr(x - a) + sqr(x - b);
end;


begin
	readln(n);

	k := 0;

	while n <> 0 do
	begin
		readln(x);
		readln(y);

		if f(x, y) <= r*r then
			k := k + 1;

		n := n - 1;
	end;

	writeln(k);
end.
