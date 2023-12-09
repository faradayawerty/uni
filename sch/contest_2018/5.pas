const n = 30;

type numbers = array[1..n] of integer;
var a : numbers;
var d, i : integer;


begin
	for i := 1 to n do
		readln(a[i], ' ');
	for i := 1 to n do
		write(a[i], ' ');
	writeln;

	d := 0;
	for i := 1 to n do
	
		if a[i] mod 2 = 0 then
			d += a[i]
		else
			d -= a[i];
	
	writeln(d);
end.

