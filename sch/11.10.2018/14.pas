var z, k : real;


function cube(x : real) : real;
begin
	cube := x*x*x;
end;


function y(x : real) : real;
begin
	y := sqr(ln(x+1)) + cube(cos(x+1));
end;


function x(z, k : real) : real;
begin
	if k < 1 then
		x := k*z*z*z
	else
		x := z*(z+1);
end;


begin
	readln(z);
	readln(k);
	writeln(y(x(z, k)));
end.
