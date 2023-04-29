@echo off
set /p folder_name=Enter project name: 
mkdir %folder_name%
cd %folder_name%

call activate base > nul 2>&1
py -m venv .\venv
call .\venv\Scripts\activate.bat
pip install flask

echo from flask import Flask > app.py
echo app = Flask(__name__) >> app.py
echo. >> app.py
echo @app.route('/') >> app.py
echo def hello(): >> app.py
echo.    return 'Hello, World!' >> app.py
echo. >> app.py
echo if __name__ == '__main__': >> app.py
echo.    app.run(debug=True) >> app.py
python .\app.py

exit
