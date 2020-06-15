/******NOT FOR USE CURRENTLY********
Functions to implement SELECT queries. Will be combined with other code once ready. */

module.exports = function(){
    var express = require('express');
    var router = express.Router();
}

function getRecipes(res, mysql, context, complete){
    mysql.pool.query("SELECT imagePath, description, instructions, prepTime, cookTime, price FROM Recipes ORDER BY _condition", function(error, results, fields){
        if(error){
            res.write(JSON.stringify(error));
            res.end();
        }
        context.recipes  = results;
        complete();
    });
}

function getMealPlans(res, mysql, context, complete){
    mysql.pool.query("SELECT filled, price, startDate, endDate FROM Meal_Plans WHERE filled = false ORDER BY startDate", function(error, results, fields){
        if(error){
            res.write(JSON.stringify(error));
            res.end();
        }
        context.meal_plans  = results;
        complete();
    });
}

function getUsers(res, mysql, context, complete){
    mysql.pool.query("SELECT firstName, lastName FROM Users ORDER BY lastName, firstName", function(error, results, fields){
        if(error){
            res.write(JSON.stringify(error));
            res.end();
        }
        context.users  = results;
        complete();
    });
}

function getOrder(res, mysql, context, complete){
    mysql.pool.query("SELECT filled, price", function(error, results, fields){
        if(error){
            res.write(JSON.stringify(error));
            res.end();
        }
        context.orders = results;
        complete();
    });
}

/*Displays all ingredients. Requires web based javascript to delete users with AJAX*/
router.get('/', function(req, res){
        var callbackCount = 0;
        var context = {};
        context.jsscripts = ["search.js"];
        var mysql = req.app.get('mysql');
        getIngredients(res, mysql, context, complete);
        function complete(){
            callbackCount++;
            if(callbackCount >= 2){
                res.render('ingredients', context);
            }

        }
    });

/*Displays one ingredient for the purpose of updating ingredient*/
router.get('/:ingredientID', function(req, res){
    callbackCount = 0;
    var context = {};
    context.jsscripts = ["select.js", "update.js"];
    var mysql = req.app.get('mysql');
    getIngredients(res, mysql, context, req.params.id, complete);
    function(complete){
        callbackCount++;
        if(callbackCount >= 2){
            res.render('update-ingredient', context);
        }
    }
});

/* Adds ingredient*/
   router.post('/', function(req, res){
        console.log(req.body.ingredients)
        console.log(req.body)
        var mysql = req.app.get('mysql');
        var sql = "INSERT INTO Ingredients(imagePath, description, unit, price, owned, bulk) VALUES(_imagePath, _description, _unit, _price, _owned, _bulk);";
        var inserts = [req.body.description, req.body.unit, req.body.price];
        sql = mysql.pool.query(sql,inserts,function(error, results, fields){
            if(error){
                console.log(JSON.stringify(error))
                res.write(JSON.stringify(error));
                res.end();
            }else{
                res.redirect('/ingredients');
            }
        });
    });

/*Updates ingredient*/
router.put('/:ingredientID', function(req, res){
    var mysql = req.app.get('mysql');
    var sql = "UPDATE Ingredients SET imagePath=?, description=?, unit=?, price=?, owned=?, bulk=? WHERE ingredientID=?";
    var inserts = [req.body.imagePath, req.body.description, req.body.unit, req.body.price, req.body.owned, req.body.bulk, req.params.ingredientID];
    sql = mysql.pool.query(sql, inserts, function(error, results, fields){
        if(error){
            res.write(JSON.stringify(error));
            res.end;
        } else{
            res.status(200);
            res.end;
        }
    });
});

/*Route to delete ingredient. */

router.delete('/:ingredientID', function(req, res){
    var mysql = req.app.get('mysql');
    var sql = "DELETE FROM Ingredients WHERE ingredientID=?";
    var inserts = [req.params.ingredientID];
    sql = mysql.pool.query(sql, inserts, function(error, results, fields){
        if(error){
            res.write(JSON.stringify(error));
            res.status(400);
            res.end();
        } else{
            res.status(202).end(); 
        }
    }
});

/*Displays all Orders. Requires web based javascript to delete users with AJAX*/
router.get('/', function(req, res){
        var callbackCount = 0;
        var context = {};
        context.jsscripts = ["search.js"];
        var mysql = req.app.get('mysql');
        getIngredients(res, mysql, context, complete);
        function complete(){
            callbackCount++;
            if(callbackCount >= 2){
                res.render('orders', context);
            }

        }
    });

/*Displays one Order for the purpose of updating Order*/
router.get('/:orderID', function(req, res){
    callbackCount = 0;
    var context = {};
    context.jsscripts = ["select.js", "update.js"];
    var mysql = req.app.get('mysql');
    getIngredients(res, mysql, context, req.params.id, complete);
    function(complete){
        callbackCount++;
        if(callbackCount >= 2){
            res.render('update-orders', context);
        }
    }
});

/* Adds Order*/
   router.post('/', function(req, res){
        console.log(req.body.ingredients)
        console.log(req.body)
        var mysql = req.app.get('mysql');
        var sql = "INSERT INTO Orders(filled, price) VALUES (_filled, _price);";
        var inserts = [req.body.description, req.body.unit, req.body.price];
        sql = mysql.pool.query(sql,inserts,function(error, results, fields){
            if(error){
                console.log(JSON.stringify(error))
                res.write(JSON.stringify(error));
                res.end();
            }else{
                res.redirect('/orders');
            }
        });
    });

/*Updates Order*/
router.put('/:orderID', function(req, res){
    var mysql = req.app.get('mysql');
    var sql = "UPDATE Orders SET imagePath=?, description=?, unit=?, price=?, owned=?, bulk=? WHERE ingredientID=?";
    var inserts = [req.body.imagePath, req.body.description, req.body.unit, req.body.price, req.body.owned, req.body.bulk, req.params.ingredientID];
    sql = mysql.pool.query(sql, inserts, function(error, results, fields){
        if(error){
            res.write(JSON.stringify(error));
            res.end;
        } else{
            res.status(200);
            res.end;
        }
    });
});

/*Route to delete Order. */

router.delete('/:orderID', function(req, res){
    var mysql = req.app.get('mysql');
    var sql = "DELETE FROM Orders WHERE orderID=?";
    var inserts = [req.params.ingredientID];
    sql = mysql.pool.query(sql, inserts, function(error, results, fields){
        if(error){
            res.write(JSON.stringify(error));
            res.status(400);
            res.end();
        } else{
            res.status(202).end(); 
        }.0
    }
});