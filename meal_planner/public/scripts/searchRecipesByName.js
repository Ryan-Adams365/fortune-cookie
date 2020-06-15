function searchRecipesByName() {
	var searchTerm = document.getElementById('searchRecipesInput').value;
	window.location = '/recipes/search/' + searchTerm;
}