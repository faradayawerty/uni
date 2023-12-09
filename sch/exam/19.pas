var a : array[1..10] of integer;
var i, imin : integer;

begin
	randomize;

	for i := 1 to 10 do
	begin 
		a[i] := random(15+27) - 27;
		write(a[i], ' ');
	end;
	writeln;

	imin := 1;
	for i := 2 to 10 do
		if a[imin] > a[i] then 
			imin := i;
	
	writeln(a[imin], ' ', imin);
end.

