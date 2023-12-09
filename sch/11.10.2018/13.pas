type coordinates = array[1..3] of real;

var x, y : coordinates;
var i : integer;


function distance(x1, y1, x2, y2 : real) : real;
begin
	distance := sqrt(sqr(x1 - x2) + sqr(y1 - y2));
end;


function area(a, b ,c : real) : real;
var p : real;
begin
	p := (a + b + c) / 2;

	area := sqrt(p*(p - a)*(p - b)*(p - c));
end;


begin
	for i := 1 to 3 do
	begin 
		readln(x[i]);
		readln(y[i]);
	end;

	writeln
	(
		area
		(
			distance(x[1], y[1], x[2], y[2]), 
			distance(x[2], y[2], x[3], y[3]), 
			distance(x[1], y[1], x[3], y[3])
		)
	);
end.
