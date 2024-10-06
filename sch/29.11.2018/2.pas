var f : text;
var i, x : integer;
var count : integer;

begin
	assign(f, 'numbers.txt');
	append(f);

	for i := 1 to 5 do
	begin
		readln(x);
		writeln(f, x);
	end;

	reset(f);
	count := 0;

	while not eof(f) do
	begin
		readln(f, x);
		count += 1;
	end;

	writeln('Количество чисел в файле = ', count);
	close(f);
end.
