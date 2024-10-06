var x, y : integer;

function gcd(a, b : integer) : integer;
begin
	if (a = 0) or (b = 0) then
		gcd := a+b
	else
		if a > b then
			gcd := gcd(a mod b, b)
		else
			gcd := gcd(b mod a, a);
end;

begin
	readln(x);
	readln(y);
	writeln(gcd(x, y));
end.

