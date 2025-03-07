
from random import random
from flask import Flask

app = Flask(__name__)

def C(n, k):
    if k == 0:
        return 1;
    return n/k * C(n - 1, k - 1);

@app.route('/tasks/1')
def task1():
    text = ""
    text += "<b>Задание 1</b> <br>"
    N = 0;
    for i in range(1000):
        num = int(random() * 90 + 10)
        if num//10 != num%10:
            N += 1
    text += str(N / 1000) + "<br>"
    text += str(1 - 9 / 90) + "<br>"
    return text

@app.route('/tasks/2')
def task2():
    text = "Задание 2" + "<br>"
    text += str(1 - 1/(2 ** 3)) + "<br>"
    return text

@app.route('/tasks/3')
def task3():
    text = str("Задание 3") + "<br> "
    text += str(1 / (6 ** 7)) + "<br> "
    return text
    
@app.route('/tasks/4')
def task4():
    text = str("Задание 4") + "<br>"
    text += str(1 / C(30, 3)) + "<br>"
    return text
    
@app.route('/tasks/5')
def task5():
    text = str("Задание 5" + "<br>")
    text += str(C(10, 2) / C(25, 10)) + "<br>"
    return text

@app.route('/tasks/6')
def tasks6():
    text = str("Задание 6" + "<br>")
    text += str(C(4,1) * C(5,1) / C(9,2)) + "<br>"
    return text
    
@app.route('/tasks/7')
def tasks7():
    text = str("Задание 7" + "<br>")
    text += str(C(45, 3) / C(90, 3)) + "<br>"
    return text
    
@app.route('/tasks/8')
def tasks8():
    text = str("Задание 8" + "<br>")
    text += str(C(2, 2) * C(18, 1) / C(20, 3)) + "<br>"
    return text
    
@app.route('/tasks/9')
def tasks9():
    text = str("Задание 9" + "<br>")
    text += str(C(8, 2) * C(8, 4) / C(16, 6)) + "<br>"
    return text

@app.route('/tasks/10')
def tasks10():
    text = str("Задание 10" + "<br>")
    text += str(C(14, 3) * C(9, 3) / C(23, 6)) + "<br>"
    return text

if __name__ == '__main__':
    app.run(debug=True)

