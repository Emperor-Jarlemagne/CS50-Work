from cs50 import SQL
from flask import Flask, redirect, render_template, request

app = Flask(__name__)

db = SQL("sqlite:///forshims.db")

REGISTRANTS = {}

SPORTS = [
    "Foosball",
    "Pesäpallo",
    "Salibandy"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/deregister", methods=["POST"])
def deregister():
    #Forget Registrant
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id = ?", id)
    return redirect("/registrants")

@app.route("/register", methods=["POST"])
def register():
    #Validate Submission
    #if not request.form.get("name") or request.form.get("sport") not in SPORTS:
    #    return render_template("failure.html")
    #Confirm registration
    #return render_template("success.html")
    #Validate Submission
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or sport not in SPORTS:
        return render_template("failure.html", message="Missing Information")

    #Remember Registrant
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name sport)

    #Confirm Registration
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)