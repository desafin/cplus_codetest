const body = document.body;
const themeToggle = document.querySelector("#theme-toggle");
const search = document.querySelector("#search");
const searchable = [...document.querySelectorAll(".searchable")];
const toast = document.querySelector("#toast");

const savedTheme = localStorage.getItem("algorithm-shelf-theme");
if (savedTheme === "dark") body.classList.add("dark");
updateThemeLabel();

themeToggle.addEventListener("click", () => {
  body.classList.toggle("dark");
  localStorage.setItem("algorithm-shelf-theme", body.classList.contains("dark") ? "dark" : "light");
  updateThemeLabel();
});

function updateThemeLabel() {
  const dark = body.classList.contains("dark");
  themeToggle.querySelector(".theme-icon").textContent = dark ? "☀" : "☾";
  themeToggle.querySelector(".theme-label").textContent = dark ? "라이트 모드" : "다크 모드";
  themeToggle.setAttribute("aria-label", dark ? "라이트 모드로 전환" : "다크 모드로 전환");
}

search.addEventListener("input", () => {
  const keyword = search.value.trim().toLowerCase();
  searchable.forEach((item) => {
    item.hidden = Boolean(keyword) && !item.dataset.search.toLowerCase().includes(keyword);
  });
});

document.addEventListener("keydown", (event) => {
  if (event.key === "/" && document.activeElement !== search) {
    event.preventDefault();
    search.focus();
  }
});

document.querySelectorAll(".copy-button").forEach((button) => {
  button.addEventListener("click", async () => {
    try {
      await navigator.clipboard.writeText(button.dataset.copy);
      toast.classList.add("show");
      setTimeout(() => toast.classList.remove("show"), 1600);
    } catch {
      button.textContent = "직접 선택";
    }
  });
});

const nodes = [...document.querySelectorAll(".node")];
const queueItems = document.querySelector("#queue-items");
const bfsStep = document.querySelector("#bfs-step");
const bfsTitle = document.querySelector("#bfs-title");
const bfsDescription = document.querySelector("#bfs-description");
const bfsStages = [
  ["01", "시작 정점을 큐에 넣어요", "방문 표시를 한 뒤, 큐에서 하나씩 꺼내 인접한 정점을 추가합니다.", [0], ["1"]],
  ["02", "1을 방문하고 이웃을 추가해요", "큐에서 1을 꺼냈어요. 아직 방문하지 않은 2와 3을 큐에 넣습니다.", [0, 1, 2], ["2", "3"]],
  ["03", "2와 3을 차례로 방문해요", "먼저 들어온 정점부터 처리합니다. 이것이 BFS가 가까운 곳을 먼저 보는 이유예요.", [0, 1, 2, 3, 4], ["4", "5"]],
  ["04", "모든 정점을 방문했어요", "큐가 비면 탐색이 끝납니다. 방문 순서는 1 → 2 → 3 → 4 → 5 입니다.", [0, 1, 2, 3, 4], []]
];
let bfsTimer;
function playBfs() {
  clearInterval(bfsTimer);
  let stage = 0;
  const render = () => {
    const [step, title, description, active, queue] = bfsStages[stage];
    bfsStep.textContent = step;
    bfsTitle.textContent = title;
    bfsDescription.textContent = description;
    nodes.forEach((node, index) => node.classList.toggle("active", active.includes(index)));
    queueItems.innerHTML = queue.length ? queue.map((value) => `<b>${value}</b>`).join("") : "<span style='color:#9daac0;font-size:11px'>empty</span>";
    stage = (stage + 1) % bfsStages.length;
  };
  render();
  bfsTimer = setInterval(render, 1900);
}
document.querySelector("#run-bfs").addEventListener("click", playBfs);
playBfs();

document.querySelectorAll(".nav-link").forEach((link) => {
  link.addEventListener("click", () => {
    document.querySelectorAll(".nav-link").forEach((item) => item.classList.remove("active"));
    link.classList.add("active");
  });
});
