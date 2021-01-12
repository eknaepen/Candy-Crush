# NodeJS API/MongoDB database
To store all client orders we set up a database with a schema for the CSV messages. To connect the Client GUI to the online MongoDB database we made API in NodeJS that runs on a heroku server. The CSV data is send via the MQTT broker from the GUI to the API and then parsed and uploaded. The message is seperated in the following catagories:

- customer name
- customer number
- X coördinates
- Y coördinates
- Z coördinates
- material
- material X coördinate
- material Y coördinate
- material Z coördinate

<br>

When the CSV message is captured it is a long string with all the data in it. This message is then split on the comma's and put in a mongoose schema to be uploaded to the MongoDB database. If the API is built it needs to be deployed, for example heroku. Create a pipeline and app on heroku and deploy the API so it is allways running and the GUI is in constant connection to the database. If the schema needs to be modified the API needs to deployed again to update te changes.
