var n, c : integer;
var t : longint;


function flip(x : longint) : longint;
begin
	flip := 0;

	while x <> 0 do
	begin
		flip *= 10;
		flip += x mod 10;
		x := x div 10;
	end;
end;


begin
	for n := 50 to 80 do
	begin
		t := n;
		c := 0;

		while t <> flip(t) do
		begin
			t += flip(t);
			c += 1;
		end;

		write(n, '-', c, ' ')
	end;
	writeln;
end.


