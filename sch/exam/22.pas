var s, z : string;
var i : integer;

begin
	readln(s);

	for i := 1 to length(s) do
	begin
		z += s[i];

		if s[i] = 'o' then
			z += '?';
	end;

	writeln(z);
end.
