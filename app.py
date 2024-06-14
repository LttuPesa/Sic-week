from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/submit-data', methods=['POST'])
def submit_data():
    data = request.get_json()
    if 'temperature' in data:
        temperature = data['temperature']
        print(f"Received temperature: {temperature}")
        # Lakukan pengolahan data di sini jika diperlukan
        
        # Berikan respons sukses
        response = {'message': 'Data received successfully', 'temperature': temperature}
        return jsonify(response), 200
    else:
        return jsonify({'error': 'No temperature data provided'}), 400

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)
