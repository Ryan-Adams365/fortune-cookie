module.exports = function(){
    var express = require('express');
    var router = express.Router();

	function getRecipes(res, mysql, output, complete){
		mysql.pool.query('SELECT recipeID, name, imagePath FROM Recipes', function(error, results, fields){
				if(error){
					res.write(JSON.stringify(error));
					res.end();
				}
				output.recipes = results;
				complete();
		});
	}

	function getRecipesWithName(req, res, mysql, output, complete){
		var query = 'SELECT recipeID, name, imagePath FROM Recipes WHERE name LIKE ' + mysql.pool.escape(req.params.searchTerm + '%');
		mysql.pool.query(query, function(error, results, fields){
				if(error){
					res.write(JSON.stringify(error));
					res.end();
				}
				output.recipes = results;
				complete();
		});
	}

    router.get('/', function(req, res){
		var callbackCount = 0;
		var output = {};
		output.scripts = ['searchRecipesByName.js', 'deleteRecipe.js'];
		var mysql = req.app.get('mysql');

		getRecipes(res, mysql, output, complete);

		function complete(){
			callbackCount++;
			if(callbackCount >= 1){
				res.render('recipes', output);
			}
		}
    });

    router.get('/search/:searchTerm', function(req, res){
		var callbackCount = 0;
		var output = {};
		output.scripts = ['searchRecipesByName.js', 'deleteRecipe.js'];
		var mysql = req.app.get('mysql');

		getRecipesWithName(req, res, mysql, output, complete);

		function complete(){
			callbackCount++;
			if(callbackCount >= 1){
				res.render('recipes', output);
			}
		}
    });

	router.delete('/:id', function(req, res){
		var mysql = req.app.get('mysql');
		var query = 'DELETE FROM Recipes WHERE recipeID = ?';
		var inserts = [req.params.id];
		mysql.pool.query(query, inserts, function(error, results, fields){
			if(error){
				console.log(error);
				res.write(JSON.stringify(error));
				res.status(400);
				res.end();
			} else{
				res.status(202);
				res.end();
			}
		})
	});

    return router;
}();