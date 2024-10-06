var s, z : string;
var i : integer;

begin
	readln(s);

	z := '';

	for i := 1 to length(s) do
		z += s[i] + ' ';
	
	writeln(z);
end.
