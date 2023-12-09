var s : string;
var c : integer;

begin
	readln(s);
	c := 0;

	{Число слов в предложении равно числу пробелов + 1}
	{Пока пробелы не исчезнут, мы будем удалять их, прибавляя 1 к счетчику пробелов}

	while pos(' ', s) <> 0 do
	begin
		delete(s, pos(' ', s), 1);
		c += 1;
	end;

	writeln(c + 1);
end.
