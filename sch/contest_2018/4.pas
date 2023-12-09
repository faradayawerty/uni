const n = 1;
const m = 1000;

var i, c: integer;

function lcm(a, b : integer) : integer;
var t : integer;
begin
	t := a*b;

	while (a <> 0) and (b <> 0) do
	begin 
		if a > b then
			a := a mod b
		else
			b := b mod a;
	end;

	if t = 0 then
		lcm := 0
	else 
		lcm := t div (a+b);
end;

function digit_lcm(x : integer) : integer;
begin
	if x div 10 = 0 then
		digit_lcm := x
	else 
		digit_lcm := lcm(x mod 10, digit_lcm(x div 10));
end;

begin
	c := 0;

	for i := n to m do
	begin
		if digit_lcm(i) = 0 then
			continue;

		if i mod digit_lcm(i) = 0 then
		begin
			write(i, ' ');
			c += 1;
		end;
	end;

	writeln;
	writeln(c);
end.

