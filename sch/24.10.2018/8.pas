var s : string;
var i, spaces : integer;

begin
	readln(s);

	spaces := 0;

	for i := 1 to length(s) do
	begin
		if s[i] = ' ' then
			spaces += 1;
	end;

	writeln(spaces + 1);
end.
