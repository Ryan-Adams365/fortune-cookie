module.exports = function(){
    var express = require('express');
    var router = express.Router();

	function getRecipes(res, mysql, output, complete){
		mysql.pool.query('SELECT name, imagePath FROM Recipes', function(error, results, fields){
				if(error){
					res.write(JSON.stringify(error));
					res.end();
				}
				output.recipes = results;
				complete();
		});
	}

    /*Display normal page*/

    router.get('/', function(req, res){
	var callbackCount = 0;
	var output = {};
	var mysql = req.app.get('mysql');
	getRecipes(res, mysql, output, complete);
	function complete(){
		callbackCount++;
		if(callbackCount >= 1){
			res.render('home', output);
		}
	}
    });

    return router;
}();