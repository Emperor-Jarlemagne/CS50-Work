from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

#Configure App
app = Flask(__name__)

#Connect to Database
db = SQL("sqlite:///store.db")

#Configure Session
app.config["SESSION_PERMANENT"]
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    books = db.execture("SELECT * FROM books")
    return render_template("books.html", books=books)

@app.route("/cart", methods=["GET", "POST"])
def cart():
    #Ensure Cart Exists
    if "cart" not in session:
        session["cart"] = []
    #POST
    if request.method == "POST":
        id = request.form.get("id")
        if id:
            session["cart"].append(id)
        return redirect("/cart")
    #GET
    books = db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    return render_template("cart.html", books=books)