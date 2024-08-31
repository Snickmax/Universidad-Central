from flask import Flask, jsonify, request, render_template
from rivescript import RiveScript

app = Flask(__name__)
bot = RiveScript()
bot.load_file('rives/inicio.rive')
bot.load_file('rives/anime.rive')
bot.load_file('rives/restaurante.rive')
bot.load_file('rives/pelis.rive')
bot.sort_replies()

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/app/", methods=["POST"])
def webhook_whatsapp():
    data = request.get_json()
    mensaje = data.get('message', '')

    if mensaje:
        respuesta = bot.reply("localuser", mensaje)
        respuesta = respuesta.replace("\\n", "\\\n").replace("\\", "")

        print(respuesta)
        print(mensaje)
        return jsonify({"response": respuesta})

    return jsonify({"response": "No message received"})

if __name__ == "__main__":
    app.run(debug=True)